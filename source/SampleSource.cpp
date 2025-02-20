#include "SampleSource.h"
#include "CodalDmesg.h"

using namespace codal;

SampleSource::SampleSource(Mixer2 &mixer, float sampleRate, float sampleRange) : MemorySource(), mixer(mixer)
{
    this->sampleRate = sampleRate;
    this->sampleRange = sampleRange;
    this->channel = this->mixer.addChannel(*this, sampleRate, sampleRange);
    connect(*channel);
}

SampleSource::~SampleSource()
{
    this->mixer.removeChannel(this->channel);
}

int SampleSource::setSampleRate(float sampleRate)
{
    this->sampleRate = sampleRate;
    this->channel->setSampleRate(sampleRate);
}

void SampleSource::setVolume(float volume)
{
    this->channel->setVolume(volume);
}