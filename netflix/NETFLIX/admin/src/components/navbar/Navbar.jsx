import './navbar.scss'
import SearchOutlinedIcon from "@mui/icons-material/SearchOutlined";
import LanguageOutlinedIcon from "@mui/icons-material/LanguageOutlined";
import DarkModeOutlinedIcon from "@mui/icons-material/DarkModeOutlined";
import FullscreenExitOutlinedIcon from "@mui/icons-material/FullscreenExitOutlined";
import NotificationsNoneOutlinedIcon from "@mui/icons-material/NotificationsNoneOutlined";
import ChatBubbleOutlineOutlinedIcon from "@mui/icons-material/ChatBubbleOutlineOutlined";
import ListOutlinedIcon from "@mui/icons-material/ListOutlined";
 

function Navbar() {
  return (
	<div className='navbar'>
		<div className="wrapper">
			<div className="search">
				<input type="search" placeholder='Search...'/>
				<SearchOutlinedIcon/>
			</div>
			<div className="items">
				<div className="item">
					<LanguageOutlinedIcon className='icon'/>
					Language
				</div>
				<div className="item">
					<DarkModeOutlinedIcon className='icon'/>
				</div>
				<div className="item">
					<FullscreenExitOutlinedIcon className='icon'/>
				</div>
				<div className="item">
					<NotificationsNoneOutlinedIcon className='icon'/>
					<div className='container'>5</div>
				</div>
				<div className="item">
					<ChatBubbleOutlineOutlinedIcon className='icon'/>
					<div className='container'>5</div>
				</div>
				<div className="item">
					<ListOutlinedIcon/>
				</div>
				<div className="item">
					<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQCTzImyvhQUIcWrDhuREGXZH_DFKEr-K4D1Q&usqp=CAU" 
					alt="" 
					className="avatar" />
				</div>
			</div>
		</div>
	</div>
  )
}

export default Navbar
