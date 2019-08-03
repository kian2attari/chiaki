/*
 * This file is part of Chiaki.
 *
 * Chiaki is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chiaki is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Chiaki.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef CHIAKI_GUI_STREAMWINDOW_H
#define CHIAKI_GUI_STREAMWINDOW_H

#include <QMainWindow>

class QLabel;
class StreamSession;

class StreamWindow: public QMainWindow
{
	Q_OBJECT

	public:
		explicit StreamWindow(StreamSession *session, QWidget *parent = nullptr);
		~StreamWindow();

	private:
		StreamSession *session;

		QLabel *imageLabel;

		void SetImage(const QImage &image);

	protected:
		void keyPressEvent(QKeyEvent *event) override;
		void keyReleaseEvent(QKeyEvent *event) override;
		void closeEvent(QCloseEvent *event) override;

	private slots:
		void FramesAvailable();
};

#endif // CHIAKI_GUI_STREAMWINDOW_H
