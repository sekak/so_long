const router = require("express").Router()
const verify = require("./verifyToken")
const Movie = require("../modules/Movie")




//POST
router.post("/", verify, async (req, res) => {
	if (req.user.admin) {
		const movie = new Movie(req.body)
		try {
			const movies = await movie.save()
			res.status(200).json(movies) 
		}
		catch (err) {
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You not have access to post.")
})



//UPDATE 
router.put("/:id", verify, async (req, res) => {
	if (req.user.admin) {
		try {
			const movie = await Movie.findByIdAndUpdate(req.params['id'], { $set: req.body }, { $new: true })
			res.status(200).json(movie)
		}
		catch (err) {
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You not have access to update.")
})

//DELETE
router.delete("/:id", verify, async (req, res) => {
	if (req.user.admin) {
		try {
			await Movie.findByIdAndDelete(req.params['id'])
			res.status(200).json("Movie is delete.")
		}
		catch (err) {
			res.status(401).json(err)
		}
	} else
		res.status(403).json("You not have access to delete.")
})


//GET movie
router.get("/:id", verify, async (req, res) => {

	try {
		const user = await Movie.findById(req.params['id'])
		res.status(200).json(user)
	}
	catch (err) {
		res.status(401).json(err)
	}
})                                                                                                                     

//GET random movie
router.get("/random", verify, async (req, res) => {
	const type = req.query.type;
	let movie;
	try {
	  if (type === "series") {
		movie = await Movie.aggregate([
		  { $match: { isSeries: true } },
		  { $sample: { size: 1 } },
		]);
	  } else {
		movie = await Movie.aggregate([
		  { $match: { isSeries: false } },
		  { $sample: { size: 1 } },
		]);
	  }
	  res.status(200).json(movie);
	} catch (err) {
	  res.status(500).json(err);
	}
  });
//GET aLL

router.get("/", verify, async (req, res) => {
	 
	if (req.user.admin) {
	try {
	  const movie = await Movie.find();
	  res.status(200).json(movie);
	} catch (err) {
	  res.status(500).json(err);
	}
	}else
	res.status(500).json("You have not athenticated.");
})

module.exports = router