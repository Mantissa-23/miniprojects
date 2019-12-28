#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <limits>
#include <iostream>
#include "util.h"

/**
 * Draws a vector as a series of increasingly tall, rainbow bars.
 *
 * Assumes vector is unchanging. If vector changes, update function
 * should be called, which scans through entire vector.
 */
template<typename T>
class VectorVisualizer : public sf::Drawable {
  public:
    VectorVisualizer(sf::FloatRect _renderArea, const std::vector<T>& _vec) : vec(_vec) {
      renderArea = _renderArea;

      const unsigned SAMPLES = 44100;
      const unsigned SAMPLE_RATE = 44100;
      const unsigned AMPLITUDE = 30000;

      sf::Int16 raw[SAMPLES];

      const double TWO_PI = 6.28318;
      const double increment = 440./44100;
      double x = 0;
      for (unsigned i = 0; i < SAMPLES; i++) {
        raw[i] = AMPLITUDE * sin(x*TWO_PI);
        x += increment;
      }

      if (!buffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
        std::cerr << "Loading failed!" << std::endl;
      }

      sound.setBuffer(buffer);
      sound.setLoop(true);

      update();
    }
    void update() {
      max_val = std::numeric_limits<T>::min();
      for(auto i : vec) {
        if(i > max_val)
          max_val = i;
      }
    }
    void drawBar(sf::RenderTarget* target, int i) {
        sf::RectangleShape bar;
        bar.setPosition(sf::Vector2f(renderArea.left + i * renderArea.width / vec.size(), renderArea.top));
        bar.setSize(sf::Vector2f(renderArea.width / (vec.size()), renderArea.height));
        bar.setFillColor(sf::Color::Black);
        target->draw(bar);

        bar.setSize(sf::Vector2f(renderArea.width / (vec.size()), renderArea.height * float(vec[i]) / float(max_val)));
        bar.setFillColor(hsl2rgb(275.0 * float(vec[i]) / float(max_val), 1.0, 0.5));
        target->draw(bar);
    }
    // Linearly interpolate between pitchmax and pitchmin
    // knowing maxval
    void pitchSound(float val) {
      sound.setPitch(((pitchmax - pitchmin) / max_val) * val + pitchmin);
    }
    void playSound() {
      sound.play();
    }
    void stopSound() {
      sound.stop();
    }

  private:
    sf::FloatRect renderArea;
    const std::vector<T>& vec;
    T max_val;

    sf::SoundBuffer buffer;
    sf::Sound sound;
    float pitchmin = 0.6f;
    float pitchmax = 4.0f;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
      for(int i = 0; i < vec.size(); i++) {
        sf::RectangleShape bar;
        bar.setPosition(sf::Vector2f(renderArea.left + i * renderArea.width / vec.size(), renderArea.top));
        bar.setSize(sf::Vector2f(renderArea.width / (vec.size()), renderArea.height * float(vec[i]) / float(max_val)));
        bar.setFillColor(hsl2rgb(275.0 * float(vec[i]) / float(max_val), 1.0, 0.5));
        target.draw(bar, states);
      }
    }
};
