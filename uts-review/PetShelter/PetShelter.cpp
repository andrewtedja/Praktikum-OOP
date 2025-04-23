#include "PetShelter.hpp"
using namespace std;

template <typename T>
PetShelter<T>::PetShelter(string shelterName)
{
    this->shelterName = shelterName;
    this->dogCapacity = 8;
    this->catCapacity = 12;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        pets[i] = nullptr;
    }
}

template <typename T>
PetShelter<T>::PetShelter(string shelterName, int dogCapacity,
                          int catCapacity)
{
    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        pets[i] = nullptr;
    }

    int totalCapacity = dogCapacity + catCapacity;
    if (totalCapacity > MAX_SHELTER_CAPACITY)
    {
        cout << "The total capacity you construct is " << totalCapacity
             << ", meanwhile the shelter capacity is 20" << endl;
    }
}

template <typename T>
PetShelter<T>::~PetShelter()
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr)
        {
            delete pets[i];
            pets[i] = nullptr;
        }
    }
}

template <typename T>
string PetShelter<T>::getShelterName() const
{
    return shelterName;
}

template <typename T>
void PetShelter<T>::addPet(const string &petName, int age, bool isDog,
                           const string &extraInfo)
{
    if (petCount >= MAX_SHELTER_CAPACITY)
    {
        cout << "Error: Shelter is at full capacity!" << endl;
        return;
    }

    if (isDog && currentDogs >= dogCapacity)
    {
        cout << "Error: No space for more dogs!" << endl;
        return;
    }

    if (!isDog && currentCats >= catCapacity)
    {
        cout << "Error: No space for more cats!" << endl;
        return;
    }

    int emptySlot = -1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] == nullptr)
        {
            emptySlot = i;
            break;
        }
    }

    if (emptySlot == -1)
    {
        cout << "Error: No available slot found!" << endl;
        return;
    }

    Pet *newPet = nullptr;
    string petID;

    if (isDog)
    {
        newPet = new Dog(petName, age, extraInfo);
        currentDogs++;
        petID = "D" + to_string(currentDogs);
    }
    else
    {
        newPet = new Cat(petName, age, extraInfo);
        currentCats++;
        petID = "C" + to_string(currentCats);
    }

    newPet->setId(petID);
    pets[emptySlot] = newPet;
    petCount++;

    cout << "Success: " << petName << " has been added as a ";
    if (isDog)
    {
        cout << "Dog";
    }
    else
    {
        cout << "Cat";
    }
    cout << "! Pet ID: " << petID << endl;
}

template <typename T>
T *PetShelter<T>::findPet(const string &petID) const
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr && pets[i]->getId() == petID)
        {
            pets[i]->displayInfo();
            return dynamic_cast<T *>(pets[i]);
        }
    }

    cout << "Pet ID is invalid!" << endl;
    return nullptr;
}

template <typename T>
void PetShelter<T>::listAllPets() const
{
    if (petCount == 0)
    {
        cout << "No pets in the shelter yet!" << endl;
        return;
    }

    int counter = 1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr)
        {
            cout << counter << ". ";
            pets[i]->displayInfo();
            counter++;
        }
    }
}

template <typename T>
int PetShelter<T>::calculateCost() const
{
    int totalCost = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr)
        {
            if (dynamic_cast<Dog *>(pets[i]))
            {
                totalCost += 75;
            }
            else if (dynamic_cast<Cat *>(pets[i]))
            {
                totalCost += 60;
            }
        }
    }

    return totalCost;
}

template <typename T>
void PetShelter<T>::removePet(const string &petID)
{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++)
    {
        if (pets[i] != nullptr && pets[i]->getId() == petID)
        {
            string petName = pets[i]->getName();

            if (dynamic_cast<Dog *>(pets[i]))
            {
                currentDogs--;
            }
            else if (dynamic_cast<Cat *>(pets[i]))
            {
                currentCats--;
            }

            delete pets[i];
            pets[i] = nullptr;
            petCount--;

            cout << petName << " has been removed from the shelter."
                 << endl;
            return;
        }
    }

    cout << "Pet ID is invalid!" << endl;
}

template class PetShelter<Pet>;