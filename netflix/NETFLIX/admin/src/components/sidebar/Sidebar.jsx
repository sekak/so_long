import './sidebar.scss'
import DashboardIcon from '@mui/icons-material/Dashboard';
import PersonOutlineOutlinedIcon from '@mui/icons-material/PersonOutlineOutlined';
import StoreMallDirectoryIcon from '@mui/icons-material/StoreMallDirectory';
import PaymentIcon from '@mui/icons-material/Payment';
import LocalShippingIcon from '@mui/icons-material/LocalShipping';
import AssessmentIcon from '@mui/icons-material/Assessment';
import NotificationsNoneIcon from '@mui/icons-material/NotificationsNone';
import SettingsIcon from '@mui/icons-material/Settings';
import ManageAccountsIcon from '@mui/icons-material/ManageAccounts';


function Sidebar() {
	return (
		<div className='sidebar'>
			<div className="top">
				<span className="logo">lamadmin</span>
			</div>
			<hr />
			<div className="center">
				<ul>
					<p className="title">MAIN</p>
					<li>
						<DashboardIcon className='icons' />
						<span>DashBorad</span>
					</li>
					<li>
						<PersonOutlineOutlinedIcon className='icons' />
						<span>Users</span>
					</li>
					<li>
						<StoreMallDirectoryIcon className='icons' />
						<span>Products</span>
					</li>
					<li>
						<PaymentIcon className='icons' />
						<span>Orders</span>
					</li>
					<li>
						<LocalShippingIcon className='icons' />
						<span>Delivery</span>
					</li>
					<p className="title">USEFUL</p>

					<li>
						<AssessmentIcon className='icons' />
						<span>Stats</span>
					</li>
					<li>
						<NotificationsNoneIcon className='icons' />
						<span>Notifications</span>
					</li>
					<p className="title">SERVICE</p>
					<li>
						<SettingsIcon className='icons' />
						<span>System Health</span>
					</li>
					<li>
						<SettingsIcon className='icons' />
						<span>Logs</span>
					</li>
					<li>
						<SettingsIcon className='icons' />
						<span>Settings</span>
					</li>
					<p className="title">USER</p>
					<li>
						<ManageAccountsIcon className='icons' />
						<span>Profile</span>
					</li>
					<li>
						<ManageAccountsIcon className='icons' />
						<span>Logout</span>
					</li>
				</ul>
			</div>
			<div className="bottom">
				<p className="title">THEME</p>
				<div className='color'>
					<div className='white'></div>
					<div className='black'></div>
				</div>
			</div>
		</div>
	)
}

export default Sidebar
