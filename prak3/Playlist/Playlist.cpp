#include <bits/stdc++.h>
#include "Playlist.hpp"
#include "Playback.hpp"
#include "Song.hpp"
#include <exception>

Playlist::Playlist(string playlistName) : name(playlistName) {};

const string &Playlist::getName() const
{
    return name;
}

const vector<Song> &Playlist::getSongs() const
{
    return songs;
}

void Playlist::addSong(const Song &song)
{
    bool found = false;
    for (int i = 0; i < songs.size(); i++)
    {
        if (songs[i] == song)
        {
            found = true;
        }
    }
    if (!found)
    {
        songs.push_back(song);
    }
}

bool Playlist::removeSong(const Song &songToRemove)
{
    for (int i = 0; i < songs.size(); i++)
    {
        if (songs[i] == songToRemove)
        {
            songs.erase(songs.begin() + i);
            return true;
        }
    }
    return false;
}

void Playlist::removeSongByIndex(size_t index)
{
    try
    {
        if (index < 0 || index >= songs.size())
        {
            throw out_of_range("Index out of range");
        }
        songs.erase(songs.begin() + index);
    }
    catch (out_of_range e)
    {
        cout << e.what() << endl;
    }
}

size_t Playlist::numberOfSongs() const
{
    return songs.size();
}

ostream &operator<<(ostream &os, const Playlist &pl)

{
    os << "Playlist: " << pl.name << " (" << pl.songs.size() << " lagu)" << endl;
    ;
    for (int i = 0; i < pl.songs.size(); i++)
    {
        os << i + 1 << ". " << pl.songs[i] << endl;
    }
    return os;
}