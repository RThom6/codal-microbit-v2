#include "SampleSource.h"
#include "CodalDmesg.h"

using namespace codal;

SampleSource::SampleSource(Mixer2 &mixer) : MemorySource(), mixer(mixer)
{
    this->channel = this->mixer.addChannel(*this);
    connect(*channel);
}

SampleSource::~SampleSource()
{
    mixer.~Mixer2();
}

// Set the sample range of the channel associated with this SampleSource
int SampleSource::setSampleRate(float sampleRate)
{
    this->sampleRate = sampleRate;
    this->channel->setSampleRate(sampleRate);
}

void SampleSource::setVolume(float volume)
{
    this->channel->setVolume(volume);
}