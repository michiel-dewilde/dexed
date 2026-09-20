#ifndef __SYNTH_TUNING_H
#define __SYNTH_TUNING_H

#include "synth.h"
#include <memory>
#include <string>

class TuningState {
public:
    virtual ~TuningState() { }

    virtual int32_t midinote_to_logfreq(int midinote) = 0;
    virtual bool is_standard_tuning() { return true; }
    virtual int scale_length() { return 12; }
    virtual std::string display_tuning_str() { return "Standard Tuning"; }

    // getTuning() removed: it was the ONLY thing in msfa that needed the
    // Surge Synth Team tuning library, and only tuning.cc -- which is JUCE
    // bound and not compiled here -- ever implemented or called it. Keeping the
    // include would have put a THIRD copy of Tunings:: into a binary that
    // already links sfizz's and Surge's, which is how you get a crash nobody
    // can read. See FINDINGS section 8.
};

std::shared_ptr<TuningState> createStandardTuning();

std::shared_ptr<TuningState> createTuningFromSCLData( const std::string &sclData );
std::shared_ptr<TuningState> createTuningFromKBMData( const std::string &kbmData );
std::shared_ptr<TuningState> createTuningFromSCLAndKBMData( const std::string &sclData, const std::string &kbmData );

#endif
