/*
	 Copyright (C) 2011 Georgia Institute of Technology

	 it under the terms of the GNU General Public License as published by
	 the Free Software Foundation, either version 3 of the License, or
	 (at your option) any later version.

	 This program is distributed in the hope that it will be useful,
	 but WITHOUT ANY WARRANTY; without even the implied warranty of
	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 GNU General Public License for more details.

	 You should have received a copy of the GNU General Public License
	 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */

#include <QtGui>
#include <default_gui_model.h>
#include <ostream>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <dirent.h>
#include "serial.h"

#define buf_max 256

class SerialComm : public DefaultGUIModel
{
	Q_OBJECT

	public:
		SerialComm(void);
		virtual ~SerialComm(void);
		virtual void execute(void);
		void customizeGUI(void);

	protected:
		virtual void update(DefaultGUIModel::update_flags_t);

	private:
		char buf[buf_max];
		char eolchar;
		int fd;
		int baudrate;
		int timeout;
		double fs;
		QComboBox *portList;
		QStatusBar *statusBar, *messageBar;
		QTimer *timer;

		private slots:
			void connectSerialComm();
		void acquireData();
		void sendCommand();
		void readCommand();
};
