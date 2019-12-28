#include <SFML/Graphics.hpp>
#include "vector_visualizer.h"
#include <vector>
#include <numeric>
#include <cstdlib>
#include <iterator>

using namespace std;

template<typename T>
class SortVisualizer {
  private:
    sf::FloatRect workspace;
    sf::RenderWindow* window;
    sf::View view;
    VectorVisualizer<T>* visualizer;
    vector<T> arr;
    float delay;
    bool draw_on_operation = false;

  public:
    SortVisualizer(sf::FloatRect _workspace, int size) {
      workspace = _workspace;

      window = new sf::RenderWindow(sf::VideoMode(200, 200), "Sort Visualizer");
      view = sf::View(_workspace);
      window->setView(view);

      arr = vector<T>(size);
      iota(arr.begin(), arr.end(), T(0));

      visualizer = new VectorVisualizer<T>(workspace, arr);

      delay = 10.0;

    }

    ~SortVisualizer() {
      delete window;
      delete visualizer;
    }

    void draw(int i) {
      visualizer->drawBar(window, i);
      window->display();
      //sf::sleep(sf::microseconds(delay));
    }

    void draw() {
      silentDraw();
      visualizer->playSound();
    }

    void silentDraw() {
      window->clear();
      window->draw(*visualizer);
      window->display();
    }

    void swap(int index1, int index2) {
      T temp = arr[index1];
      arr[index1] = arr[index2];
      arr[index2] = temp;
      visualizer->pitchSound(arr[index1]);
      if(draw_on_operation)
        draw();
    }

    void assign(int i, T val) {
      arr[i] = val;
      visualizer->pitchSound(val);
      if(draw_on_operation)
        draw();
    }

    void assign(typename vector<T>::iterator location, T val) {
      *location = val;
      visualizer->pitchSound(val);
      if(draw_on_operation)
        draw();
    }

    void shuffle() {
      delay = 1.0;
      for(int i = 0; i < arr.size(); i++) {
        swap(i, rand() % (arr.size() - i) + i);
        draw();
      }
    }

    void mergesort(typename vector<T>::iterator start, typename vector<T>::iterator end) {
      draw_on_operation = true;
      delay = 10.0;
      if(end - start == 1)
        return;
      typename vector<T>::iterator midpoint = start + ((end - start) / 2);
      mergesort(start, midpoint);
      mergesort(midpoint, end);
      merge(start, midpoint, end);
    }

    void merge(typename vector<T>::iterator start, typename vector<T>::iterator midpoint, typename vector<T>::iterator end) {
      vector<T> scratch;
      {
        typename vector<T>::iterator i = start, j = midpoint;
        while(i < midpoint || j < end) {
          if((*i <= *j && i < midpoint) || j == end) {
            scratch.push_back(*i); 
            i++;
          }
          if((*j < *i && j < end) || i == midpoint) {
            scratch.push_back(*j);
            j++;
          }
        }
      }
      typename vector<T>::iterator i = start;
      for(auto j = scratch.begin(); j < scratch.end(); j++) {
        assign(i, *j);
        i++;
      }
    }

    void quicksort(int start, int end) {
      draw_on_operation = true;
      delay = 10.0;
      if(end - start <= 1)
        return;
      swap(rand() % (end - start) + start, end - 1);
      T pivot = arr[end - 1];
      int i = start, j = end - 2;
      while(i < j) {
        if(arr[i] < pivot) {
          i++;
          continue;
        }
        else {
          swap(i, j);
          j--;
        }
      }
      if(arr[i] < pivot) {
        swap(i + 1, end - 1);
        quicksort(start, i + 1);
        quicksort(i + 2, end);
      }
      else {
        swap(i, end - 1);
        draw();
        quicksort(start, i);
        quicksort(i + 1, end);
      }
    }

    void bubblesort() {
      delay = 0.001;
      draw_on_operation = true;

      bool sorted = false;
      while(!sorted) {
        sorted = true;
        for(int i = 0; i < arr.size() - 1; i++) {
          if(arr[i] > arr[i + 1]) {
            swap(i, i + 1);
            sorted = false;
          }
        }
        /* draw(); */
      }
    }

    void selectionsort() {
      draw_on_operation = true;

      for(int i = 0; i < arr.size(); i++) {
        int index = -1;
        T max = numeric_limits<T>::max();
        for(int j = i; j < arr.size(); j++) {
          if(arr[j] < max) {
            max = arr[j];
            index = j;
          }
        }
        swap(i, index);
      }
    }

    void insertionsort() {
      draw_on_operation = true;

      for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j > 0; j--) {
          if(arr[j - 1] > arr[j]) {
            swap(j - 1, j);
          }
        }
        /* draw(); */
      }
    }

    void cocktailShakerSort() {
      delay = 0.001;
      draw_on_operation = true;

      bool sorted = false;
      while(!sorted) {
        sorted = true;
        for(int i = 0; i < arr.size() - 1; i++) {
          if(arr[i] > arr[i + 1]) {
            swap(i, i + 1);
            sorted = false;
          }
        }
        for(int i = arr.size() - 1; i > 0; i--) {
          if(arr[i] < arr[i - 1]) {
            swap(i, i - 1);
            sorted = false;
          }
        }
        /* draw(); */
      }
    }

    int mainloop() {
      while(window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
          if(event.type == sf::Event::Closed)
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
          shuffle();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
          mergesort(arr.begin(), arr.end());
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
          quicksort(0, arr.size());
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
          bubblesort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
          selectionsort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
          insertionsort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
          cocktailShakerSort();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          window->close();
        visualizer->stopSound();

        silentDraw();
      }

      return 0;
    }
};

int main() {
  SortVisualizer<int> sort_visualizer(
      sf::FloatRect(0.f, 0.f, 1280.f, 780.f),
      1000
      );
  return sort_visualizer.mainloop();
}

