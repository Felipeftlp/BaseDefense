#ifndef PROJETIL_INIMIGO_HPP
#define PROJETIL_INIMIGO_HPP

#include <SFML/Graphics.hpp>
#include "texture_manager.h"
using namespace std;
using namespace sf;

class ProjetilInimigo : public Drawable {
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        Vector2f position;
        Vector2f direction;
        float speed;
        Sprite sprite;
        bool active;

    public:
        ProjetilInimigo(const sf::Vector2f& startPosition, const sf::Vector2f& targetPosition, TextureManager& textureManager);
        
        void update(float deltaTime);
        bool isOutOfWindow(const sf::RenderWindow& window) const;
        bool iscollidingBase(float projX, float projY, float projRadius, float baseX, float baseY, float baseRadius) const;
        bool iscolliding(float x1, float y1, float r1, float x2, float y2, float r2);
        // CircleShape getShape() const;
        Sprite& getSprite();
        void setActive(bool isActive);
        bool isActive() const;
        FloatRect getGlobalBounds() const;
};

#endif // PROJETIL_INIMIGO_HPP