 import PersonOutlinedIcon from "@mui/icons-material/PersonOutlined";
import AccountBalanceWalletOutlinedIcon from "@mui/icons-material/AccountBalanceWalletOutlined";
 import MonetizationOnOutlinedIcon from "@mui/icons-material/MonetizationOnOutlined";

export const data=[
	{
		 id:1,
		 title:"USERS",
		 amount:120,
		 link:"See all users",
		 icon:(
			<PersonOutlinedIcon className="icon" style={{color: "crimson",
			backgroundColor: "rgba(255, 0, 0, 0.2)"}}/>
		 )
	},
	{
		id:2,
		 title:"ORDER",
		 amount:100,
		 link:"View net earnings",
		 icon:(
			<MonetizationOnOutlinedIcon className="icon" style={{color: "goldenrod",backgroundColor: "rgba(218, 165, 32, 0.2)"}}/>
		 )
	},
	{
		id:3,
		 title:"EARNINGS",
		 link:"See all users",
		 amount:200,
		 icon:(
			<PersonOutlinedIcon className="icon"  style={{color: "green",backgroundColor: "rgba(0, 128, 0, 0.2)"}}/>
		 )
	},
	{
		id:4,
		 title:"BALANCE",
		 amount:320,
		 link:"See details",
		 icon:(
			<AccountBalanceWalletOutlinedIcon className="icon"   style={{color: "purple", backgroundColor: "rgba(128, 0, 128, 0.2)"}}/>
		 )
	},

]
 
 