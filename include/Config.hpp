#ifndef CONFIG_HPP
#define CONFIG_HPP

#define SUCCESS 0
#define ERROR 1

#define largura 20
#define altura 30
#define MAX_length (largura * altura)

#define pixels_per_square_in_grid 15

#define largura_in_pixels (largura * pixels_per_square_in_grid)
#define altura_in_pixels (altura * pixels_per_square_in_grid)

#define speed sf::seconds(0.1f)

#define Mesma_posicao(a, b) (a == b->getPosition())

#endif
