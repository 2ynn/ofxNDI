#pragma once

#include "ofConstants.h"
#include "ofxNDI.h"
#include <Processing.NDI.Lib.h>
#include <string>

namespace ofxNDI {
namespace Send {
class Sender
{
public:
	using Instance = NDIlib_send_instance_t;
	~Sender();
	
	bool setup(const std::string &name, const std::string &group="", bool clock_video=false, bool clock_audio=false);
	void clear();
	void addConnectionMetadata(const std::string &metadata, int64_t timecode=NDIlib_send_timecode_synthesize) const;
	void clearConnectionMetadata() const;
	
	bool isSetup() const { return instance_ != nullptr; }
	int getNumConnected(int64_t timeout_ms=0) const;
	bool isConnected(int64_t timeout_ms=0) const;
	
	bool getTally(bool *on_program, bool *on_preview, int64_t timeout_ms) const;
	bool setTally(bool on_program, bool on_preview) const;
	void setFailover(const Source &source) const;
	
	NDIlib_send_instance_t getInstance() const { return instance_; }
	ofxNDI::Source getSourceName() const;
private:
	NDIlib_send_instance_t instance_=nullptr;
};
}}

using ofxNDISender = ofxNDI::Send::Sender;
