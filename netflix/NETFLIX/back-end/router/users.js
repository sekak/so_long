const router = require("express").Router()
const verify = require("./verifyToken")
const User = require('../modules/User')
const CryptoJS = require('crypto-js')




//UPDATE
router.put("/:id", verify, async (req, res) => {
	if (req.user.id === req.params['id'] || req.user.isAdmin) {
		if (req.body.password)
			req.body.password = CryptoJS.AES.encrypt(req.body.password, 'secret key 123').toString()
		try {
			const updateUser = await User.findByIdAndUpdate(req.params['id'], { $set: req.body }, { new: true })
			res.status(200).json(updateUser)
		}
		catch (err) {
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You can update only your account.")
})



//GET 
router.get("/find/:id", async (req, res) => {
	try {
		const user = await User.findById(req.params['id'])
		!user && res.status(404).json("Not Found this Id")
		const {password , ...info} = user._doc
 		res.status(200).json(info)
	} catch (err) {
		res.status(500).json(err)
	}
})

//DELETE
router.delete("/:id", verify, async (req, res) => {
	if (req.user.id === req.params['id'] || req.user.isAdmin) {
		try {
		    await User.findByIdAndDelete(req.params['id'])
			res.status(200).json("Delete")
		}
		catch (err) {
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You can delete only your account.")
})

//GET ALL
router.get("/getusers", verify, async (req, res) => {
	const query = req.query.new
	console.log(req.user.admin)
	if (req.user.admin) {
		try {
		  const user = query ?  await User.find().sort({_id: -1}).limit(2) : await User.find()
			res.status(200).json(user)
		}
		catch (err) { 
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You are not allowed to see all user!")
})

//state user
router.get("/stats", async (req, res) => {
	const today = new Date();
	const latYear = today.setFullYear(today.setFullYear() - 1);
 
	try {
	  const data = await User.aggregate([
		{
		  $project: {
			month: { $month: "$createdAt" },
		  },
		},
		{
		  $group: {
			_id: "$month",
			total: { $sum: 1 },
		  },
		},
	  ]);
	  res.status(200).json(data)
	} catch (err) {
	  res.status(500).json(err);
	}
  });
  

module.exports = router