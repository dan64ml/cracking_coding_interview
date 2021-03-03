/*********************************************************************************
 * Очередь из кошек и собак... 
 ********************************************************************************/

#include <list>
#include <stdexcept>

using namespace std;

namespace ch03 {

// Скучная задача... Можно конечно запилить иерархию зверей, шаблонную dequeue<Animal> 
// и т.д... Всё O(1)
class AnimalQueue {
    public:
        AnimalQueue() = default;
        void enqueue(char a) { 
            if (a == 'd') {
                dogs_.push_back(time_stamp_++);
            } else if (a == 'c') {
                cats_.push_back(time_stamp_++);
            } else {
                throw runtime_error("Unknown animal");
            }
        }

        char dequeueAny() {
            int cat_time = cats_.empty() ? numeric_limits<int>::max() : cats_.front();
            int dog_time = dogs_.empty() ? numeric_limits<int>::max() : dogs_.front();

            if (cat_time == dog_time) {
                throw runtime_error("Queue is empty");
            }

            return (cat_time > dog_time) ? 'd' : 'c';
        }

        char dequeueDog() {
            if (dogs_.empty()) {
                throw runtime_error("Dogs queue is empty");
            }

            return 'd';
        }

        char dequeueCat() {
            if (cats_.empty()) {
                throw runtime_error("Cats queue is empty");
            }

            return 'c';
        }

    private:
        list<int> dogs_;
        list<int> cats_;
        int time_stamp_ = 0;
};

} // namespace ch03
