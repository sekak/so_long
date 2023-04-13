const mongose = require('mongoose')
const CryptoJS = require("crypto-js");
  

const listSchema = new mongose.Schema({
	title: { type: String, required: true, unique: true },
	type: { type: String },
	genre: { type: String },
	content: { type: Array },
}, { timestamps: true })
 

module.exports = mongose.model("List", listSchema);