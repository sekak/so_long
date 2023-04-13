
const router = require("express").Router()
const verify = require("./verifyToken")
const List = require("../modules/List")




//POST
router.post("/", verify, async (req, res) => {
	if (req.user.admin) {
		const listNew = new List(req.body)
		try {
			const list = await listNew.save()
			res.status(200).json(list)
		}
		catch (err) {
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You not have access to post.")
})

//DELETE
router.delete("/:id", verify, async (req, res) => {
	if (req.user.admin) {
		try {
			await List.findByIdAndDelete(req.params['id'])
			res.status(200).json("List is delete.")
		}
		catch (err) {
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You not have access to delete.")
})
//GET aLL

router.get("/", verify, async (req, res) => {
	const typeQuary = req.query.type 
	const genreQuary = req.query.genre
	let list = [];
	try{
		if(typeQuary)
		{
			if(genreQuary)
			{
				list = await List.aggregate([
					{$sample:{size:10}},
					{$match:{type:typeQuary , genre:genreQuary}},
				])
			}else{
				list =await List.aggregate([
					{$sample:{size:10}},
					{$match:{type:typeQuary}},
				])
			}
		}else{
			list =await  List.aggregate([
				{$sample:{size:10}},
			])
		}
		res.status(200).json(list);

	}
	catch(err)
	{
		res.status(500).json(err);
	}

})

module.exports = router