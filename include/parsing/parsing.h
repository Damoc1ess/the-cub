#ifndef PARSING_H
# define PARSING_H

//Parsing
void    parsing(int argc, char **argv, t_cub cub);
void    parse_files(char *argv[1], t_cub cub);

typedef struct s_cub
{
    // Textures
    char *north_texture;  // Chemin de la texture Nord
    char *south_texture;  // Chemin de la texture Sud
    char *west_texture;   // Chemin de la texture Ouest
    char *east_texture;   // Chemin de la texture Est

    // Couleurs
    int floor_color;      // Couleur du sol (en hexadécimal : 0xRRGGBB)
    int ceiling_color;    // Couleur du plafond (en hexadécimal : 0xRRGGBB)

    // Carte
    char **map;           // Tableau 2D représentant la carte
    int map_width;        // Largeur de la carte
    int map_height;       // Hauteur de la carte

    // Joueur
    float player_x;       // Position X du joueur
    float player_y;       // Position Y du joueur
    float player_angle;   // Angle de vue du joueur

    // MiniLibX
    void *mlx;            // Pointeur pour MiniLibX
    void *window;         // Fenêtre MiniLibX
} t_cub;

#endif