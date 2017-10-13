//
// Created by Глеб Калинин on 20.09.17.
//

#ifndef LAB3_1_QUEUEWITHPRIORITY_H
#define LAB3_1_QUEUEWITHPRIORITY_H

#include <string>
#include <list>
#include <vector>

using namespace std;

enum ElementPriority
{
    LOW,
    NORMAL,
    HIGH
};

struct QueueElement {
    string name;
};

// Для заполнения вектора с элементами
struct prioritizedElement {
    QueueElement element;
    ElementPriority priority;
};

typedef list<QueueElement> elementList;

class QueueWithPriority
{
private:
    elementList _hPriority, _nPriority, _lPriority;
public:
    void putElementToQueue(
            const QueueElement &element, const ElementPriority priority)
    {
        elementList *targetList = nullptr;

        switch (priority) {
            case HIGH:   targetList = &_hPriority; break;
            case NORMAL: targetList = &_nPriority; break;
            case LOW:    targetList = &_lPriority; break;
        }

        targetList->push_back(element);
    }

    QueueElement getElementFromQueue()
    {
        QueueElement element = QueueElement();
        vector<elementList*> priorityLists = {
                &_hPriority, &_nPriority, &_lPriority
        };

        for (auto list : priorityLists) {
            if (!list->empty()) {
                element = list->front();
                list->pop_front();

                break;
            }
        }

        return element;
    };

    // Все элементы с приоритетом low находящиеся в момент акселерации в очереди
    // увеличивают свой приоритет до high и «обгоняют» элементы с приоритетом normal
    QueueWithPriority& accelerate()
    {
        _hPriority.splice(
                _hPriority.end(),
                _lPriority
        );

        return *this;
    };

    QueueWithPriority& prnt()
    {
        vector<elementList*> priorityLists = {
                &_hPriority, &_nPriority, &_lPriority
        };

        for (auto list : priorityLists) {
            for (const auto &element : *list) {
                cout << element.name << " ";
            }
        }

        cout << endl;

        return *this;
    };
};

#endif //LAB3_1_QUEUEWITHPRIORITY_H
