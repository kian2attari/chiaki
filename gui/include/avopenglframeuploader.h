// SPDX-License-Identifier: LicenseRef-GPL-3.0-or-later-OpenSSL

#ifndef CHIAKI_AVOPENGLFRAMEUPLOADER_H
#define CHIAKI_AVOPENGLFRAMEUPLOADER_H

#include <QObject>
#include <QOpenGLWidget>

#include <zmq.h>

extern "C"
{
#include <libavcodec/avcodec.h>
}
extern "C" {
    #include "libswscale/swscale.h"
}
#include <opencv2/core/core.hpp>


class AVOpenGLWidget;
class VideoDecoder;
class QSurface;

class AVOpenGLFrameUploader: public QObject
{
	Q_OBJECT

	private:
		VideoDecoder *decoder;
		AVOpenGLWidget *widget;
		QOpenGLContext *context;
		QSurface *surface;

    private:        
        void *z_context;
        void *z_socket;
        void SendFrame(AVFrame *frame);
        
        
	private slots:
		void UpdateFrame();

	public:
		AVOpenGLFrameUploader(VideoDecoder *decoder, AVOpenGLWidget *widget, QOpenGLContext *context, QSurface *surface);
        ~AVOpenGLFrameUploader();
};

#endif // CHIAKI_AVOPENGLFRAMEUPLOADER_H
