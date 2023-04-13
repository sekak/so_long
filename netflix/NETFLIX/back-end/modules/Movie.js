const mongose = require('mongoose')


const movieSchema = new mongose.Schema({
	title: { type: String, required: true, unique: true },
	desc: { type: String },
	duration: { type: String },
	img: { type: String },
	imgTitle: { type: String },
	imgSm: { type: String },
	trailer: { type: String },
	video: { type: String },
	year: { type: String },
	limit: { type: Number },
	genre: { type: String },
	isSeries: { type: Boolean, default: false },
}, { timestamps: true }) 


module.exports = mongose.model("Movie", movieSchema);