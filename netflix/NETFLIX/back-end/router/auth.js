const router = require('express').Router()
const User = require('../modules/User')
const CryptoJS = require('crypto-js')
const JWT = require('jsonwebtoken')

router.post("/register", async (req, res) => {
	const newUser = new User({
		username: req.body.username,
		email: req.body.email,
		password: CryptoJS.AES.encrypt(req.body.password, 'secret key 123').toString()
	})
	try {
		const user = await newUser.save()
		res.status(200).json(user);
	} catch (err) {
		res.status(500).json(err)
	}
})

 
router.post("/login", async (req, res) => {
 
	try {
		
		const user = await User.findOne({email:req.body.email})
		!user && res.status(404).json("Wrong password or email")

 		const decrypt = CryptoJS.AES.decrypt(user.password, 'secret key 123').toString(CryptoJS.enc.Utf8)
		 decrypt !== req.body.password && res.status(404).json("Wrong password or email")
		 const accessToken = JWT.sign({id: user._id , admin: user.isAdmin},"secret",{expiresIn:"5d"})
		 const {password, ...info} = user._doc
		//  console.log(info) 
 		res.status(200).json({...info , accessToken})
	} catch (err) {
		res.status(500).json(err)
	}
})



module.exports = router