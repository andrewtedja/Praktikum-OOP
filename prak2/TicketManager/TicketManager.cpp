#include <iostream>
#include "TicketManager.hpp"
using namespace std;

TicketManager::TicketManager(string eventName)
{
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentRegularTickets = 0;
    this->currentVIPTickets = 0;
}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity)
{
    int total = vipCapacity + regularCapacity;
    if (total > VENUE_CAPACITY)
    {
        cout << "The total capacity you construct is " << total << ", meanwhile the venue capacity is 15" << endl;
    }
    this->eventName = eventName;
    this->vipCapacity = vipCapacity;
    this->regularCapacity = regularCapacity;
    this->ticketCount = 0;
    this->currentRegularTickets = 0;
    this->currentVIPTickets = 0;
}

TicketManager::~TicketManager()
{
    // delete[] *tickets;
    for (int i = 0; i < VENUE_CAPACITY; i++)
    {
        tickets[i] = nullptr;
    }
}

string TicketManager::getEventName() const
{
    return eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP)
{
    if (ticketCount >= VENUE_CAPACITY)
    {
        cout << "Error: All tickets are sold out!" << endl;
        return;
    }
    if (isVIP)
    {
        string ticketID;
        if (vipCapacity == currentVIPTickets)
        {
            cout << "Error: No VIP tickets left!" << endl;
            return;
        }
        this->currentVIPTickets++;
        ticketID = "V" + to_string(this->currentVIPTickets);
        tickets[ticketCount] = new VIPTicket(ticketID, ownerName);
        cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << ticketID << endl;
    }
    else
    {
        string ticketID;
        if (regularCapacity == currentRegularTickets)
        {
            cout << "Error: No Regular tickets left!" << endl;
            return;
        }
        this->currentRegularTickets++;
        ticketID = "R" + to_string(this->currentRegularTickets);
        tickets[ticketCount] = new RegularTicket(ticketID, ownerName);
        cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << ticketID << endl;
    }
    ticketCount++;
}

void TicketManager::checkTicket(const string &ticketID) const
{
    for (int i = 0; i < ticketCount; i++)
    {
        if (tickets[i]->getTicketID() == ticketID)
        {
            tickets[i]->printTicket();
            return;
        }
    }
    cout << "Ticket ID is invalid!" << endl;
}
/* Mengecek apakah tiket dengan ID tertentu valid.
 * Input:
 * - ticketID: ID tiket yang ingin diperiksa.
 *
 * Output:
 * - Jika ditemukan, cetak detail tiket menggunakan metode printTicket().
 * - Jika tidak ditemukan, cetak "Ticket ID is invalid!".
 */

void TicketManager::listAudience() const
{
    if (this->ticketCount == 0)
    {
        cout << "No audience yet!" << endl;
        return;
    }

    for (int i = 0; i < this->ticketCount; i++)
    {
        cout << i + 1 << ". ";
        tickets[i]->printTicket();
    }
}
/* Menampilkan daftar semua pemegang tiket.
 * Output:
 * - Jika belum ada yang membeli tiket, cetak "No audience yet!".
 * - Jika ada, cetak dalam format:
 *   "<nomor>. <printTicket()>"
 *
 * - Nomor urut dalam output harus dimulai dari 1.
 */

int TicketManager::calculateRevenue() const
{
    return this->currentVIPTickets * 500 + this->currentRegularTickets * 275;
}
/* Menghitung total pendapatan dari tiket yang terjual.
 * - Tiket VIP seharga 500.
 * - Tiket Regular seharga 275.
 *
 * Output: Total pendapatan dalam bentuk integer.
 */