#include "Playback.hpp"
#include <iostream>

void Playback::addToQueue(const Song &song)
{
    playbackQueue.push(song);
}

void Playback::addToQueue(const Playlist &playlist)
{
    for (int i = 0; i < playlist.numberOfSongs(); i++)
    {
        playbackQueue.push(playlist.getSongs()[i]);
    }
}

void Playback::next()
{
    if (playbackQueue.empty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    cout << "Memutar: " << playbackQueue.front() << endl;
    playbackQueue.pop();
}

void Playback::playAll()
{
    if (playbackQueue.empty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }

    while (playbackQueue.size())
    {
        next();
    }
}

void Playback::skip()
{
    if (playbackQueue.empty())
    {
        cout << "Antrian kosong" << endl;
        return;
    }
    playbackQueue.pop();
}

void Playback::clearQueue()
{
    while (playbackQueue.size())
    {
        skip();
    }
}

bool Playback::isEmpty() const
{
    return playbackQueue.empty();
}

size_t Playback::queueSize() const
{
    return playbackQueue.size();
}
