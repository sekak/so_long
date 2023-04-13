import './widget.scss'
import KeyboardArrowUpIcon from '@mui/icons-material/KeyboardArrowUp';
import KeyboardArrowDownIcon from '@mui/icons-material/KeyboardArrowDown';
import PersonOutlineOutlinedIcon from '@mui/icons-material/PersonOutlineOutlined';
 
function Widget({item}) {

	
  return (
	<div className='widget'>
		<div className="left">
			<span className="title">{item.title}</span>
			<span className="counter">{item.amount}</span>
			<span className="link">{item.link}</span>
		</div>
		<div className="right">
			<div className="percentage positive">
				<KeyboardArrowUpIcon/>
				+5 %</div>
				{item.icon}
		</div>
	</div>
  )
}

export default Widget
 