#include "SampleSource.h"
#include "CodalDmesg.h"

using namespace codal;

SampleSource::SampleSource(Mixer2 &mixer) : MemorySource(), mixer(mixer)
{
    this->mixer.addChannel(*this);
}

SampleSource::~SampleSource()
{
    mixer.~Mixer2();
}

int SampleSource::setSampleRate(float sampleRate)
{
    this->sampleRate = sampleRate;
    this->mixer.setSampleRate(sampleRate);
}

int SampleSource::setSampleRange(uint8_t sampleRange)
{
    this->sampleRate = sampleRange;
    this->mixer.setSampleRange(sampleRange);
}