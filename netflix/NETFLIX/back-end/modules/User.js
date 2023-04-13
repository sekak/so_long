const mongose = require('mongoose')


const UserSchema = new mongose.Schema({
	username: {type: String , required: true, unique: true},
	email: {type: String , required: true, unique: true},
	password: {type: String , required: true },
	imgUser: {type: String , default: ""},
	isAdmin: {type: Boolean, default : false },
},{timestamps:true})


module.exports = mongose.model("User",UserSchema);