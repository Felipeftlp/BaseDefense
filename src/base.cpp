#include "../include/base.h"
#include "../include/projetil_inimigo.h"
#include "../include/inimigo.h"
#include <algorithm>
#include <iostream>

Base::Base() : health(100) {
    shape.setSize(sf::Vector2f(300, 150)); // Define o tamanho da base
    shape.setFillColor(sf::Color::Transparent); // Sem preenchimento
    shape.setOutlineColor(sf::Color(34, 139, 34));  // Cor do contorno
    shape.setOutlineThickness(5);// Ajuste a posição da base conforme necessário
}

template <typename T>
T clampe(T value, T min, T max) {
    return std::max(min, std::min(value, max));
}

bool isCircleCollidingWithRectangle(float circleX, float circleY, float circleRadius,
                                     float rectX, float rectY, float rectWidth, float rectHeight) {
    // Encontra o ponto mais próximo no retângulo ao centro do círculo
    float closestX = std::max(rectX, std::min(circleX, rectX + rectWidth));
    float closestY = std::max(rectY, std::min(circleY, rectY + rectHeight));

    // Calcula a distância entre o ponto mais próximo e o centro do círculo
    float dx = circleX - closestX;
    float dy = circleY - closestY;
    float distanceSquared = dx * dx + dy * dy;

    return distanceSquared <= circleRadius * circleRadius;
}

void Base::update(std::list<ProjetilInimigo>& projeteis, std::vector<Inimigo>& inimigos) {
    // Verificar colisões com projéteis
    for (auto it = projeteis.begin(); it != projeteis.end();) {
        if (it->isActive()) {
            auto projShape = it->getShape();
            float projX = projShape.getPosition().x;
            float projY = projShape.getPosition().y;
            float projRadius = projShape.getRadius();

            // Debug: imprimir posição do projétil
            std::cout << "Projétil posição: (" << projX << ", " << projY << ") com raio: " << projRadius << std::endl;

            if (isCircleCollidingWithRectangle(
                    projX,
                    projY,
                    projRadius,
                    shape.getPosition().x,
                    shape.getPosition().y,
                    shape.getGlobalBounds().width,
                    shape.getGlobalBounds().height)) {
                std::cout << "Colidiu com a base!\n";
                health -= 2; // Reduz a vida da base
                it = projeteis.erase(it); // Remove o projétil
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }

    // Verificar colisões com inimigos
    for (auto it = inimigos.begin(); it != inimigos.end();) {
        if (it->isAliveStatus()) {
            auto inimigoSprite = it->getSprite();
            float inimigoX = inimigoSprite.getPosition().x;
            float inimigoY = inimigoSprite.getPosition().y;
            float inimigoWidth = inimigoSprite.getGlobalBounds().width;
            float inimigoHeight = inimigoSprite.getGlobalBounds().height;
            float inimigoRadius = std::min(inimigoWidth, inimigoHeight) / 2;

            if (isCircleCollidingWithRectangle(
                    inimigoX + inimigoRadius,
                    inimigoY + inimigoRadius,
                    inimigoRadius,
                    shape.getPosition().x,
                    shape.getPosition().y,
                    shape.getGlobalBounds().width,
                    shape.getGlobalBounds().height)) {
                health -= 5; // Reduz a vida da base
                it = inimigos.erase(it); // Remove o inimigo da lista
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }

    if (health <= 0) {
        health = 0; // Garante que a vida não fique negativa
    }
}

void Base::setPosition(const sf::Vector2f &position) {
    shape.setPosition(position);
}

int Base::getHealth() const {
    return health;
}


int Base::reduceHealth(int reduce) {
    health = health-reduce;
}

sf::RectangleShape Base::getShape() const {
    return shape;
}

bool Base::isAliveStatus() const {
    return health > 0;
}

void Base::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}
void Base::reset() {
    // Redefine a saúde e posição da base
    health = 100; // Defina o valor inicial de saúde
    // Posicione a base na posição inicial
    
}