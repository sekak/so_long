import Navbar from '../../components/navbar/Navbar'
import Sidebar from '../../components/sidebar/Sidebar'
import Widget from '../../components/widget/Widget'
import { data } from '../../components/widget/data'

import './home.scss'
import Featured from '../../components/featured/Featured'
import Chart from '../../components/chart/Chart'

function Home() {



	return (
		<div className='home'>
			<Sidebar />
			<div className="homeContainer">
				<Navbar />
				<div className="widgets">
					{data.map((item) => {
						return (
 							<Widget key={item.id} item={item} />
 						)
					})}
				</div>
				<div className='feature'>
				 <Featured/>
				 <Chart/>
				 </div>
			</div>
		</div>
	)
}

export default Home
