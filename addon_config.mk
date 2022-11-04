meta:
	ADDON_NAME = ofxNDI
	ADDON_DESCRIPTION = NewTek NDI SDK Wrapper for openFrameworks. https://www.newtek.com/ndi/
	ADDON_AUTHOR = Nariaki Iwatani
	ADDON_TAGS = "NDI" "Network" "Video"
	ADDON_URL = https://github.com/2ynn/ofxNDI
	# Forked from https://github.com/nariakiiwatani/ofxNDI

osx:
	ADDON_LDFLAGS = -Xlinker -rpath -Xlinker @executable_path

linux64:
	ADDON_LIBS = libs/NDI/lib/x86_64-linux-gnu/libndi.so.5.1.1
	ADDON_LIBS += libs/NDI/lib/x86_64-linux-gnu/libndi.so
	ADDON_LIBS += libs/NDI/lib/x86_64-linux-gnu/libndi.so.5

vs:
	ADDON_DLLS_TO_COPY += windows-copy-to-bin/Processing.NDI.Lib.Advanced.x64.dll
	ADDON_DLLS_TO_COPY += windows-copy-to-bin/Processing.NDI.Lib.Advanced.x86.dll
