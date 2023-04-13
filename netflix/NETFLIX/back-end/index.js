const express = require('express')
const app = express();
const authRouter = require('./router/auth')
const userRouter = require('./router/users')
const movieRouter = require('./router/movie')
const listRouter = require('./router/lists')
const mongose = require('mongoose')
const env = require('dotenv')
const cors = require('cors')
env.config();

mongose.connect(process.env.DB,{useNewUrlParser:true}).then(()=>console.log("MongoDB Connect!")).catch((err)=>console.log(err));
 

app.use(express.json())
app.use(cors())

app.use("/api/auth",authRouter)
app.use("/api/user",userRouter)
app.use("/api/movies",movieRouter)
app.use("/api/list",listRouter)


app.listen(8080 , ()=>{
	console.log("Server is running!")
})