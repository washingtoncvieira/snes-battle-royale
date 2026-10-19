#include <snes.h>

// Posições do jogador na tela (Visão de cima / Top-Down)
u16 player_x = 128;
u16 player_y = 112;
u8 player_hp = 100;
u8 alive_players = 30; // 30 Jogadores/Bots na partida

int main(void) {
    // Inicializa a tela do SNES
    consoleInit();
    
    // Interface do jogo (HUD)
    consoleDrawText(3, 1, "=== BATTLE ROYALE 16-BIT ===");
    consoleDrawText(2, 3, "SOBREVIVENTES: %d / 30", alive_players);
    consoleDrawText(2, 4, "VIDA:          %d HP", player_hp);
    consoleDrawText(2, 6, "MAPA: ILHA PRINCIPAL");

    // Desenha a representação do seu personagem
    consoleDrawText(player_x / 8, player_y / 8, "P1");

    // Loop principal (60 FPS)
    while (1) {
        // Leitura dos botões do controle do emulador
        u16 pad = padsCurrent(0);

        // Movimentação do personagem com o D-Pad
        if (pad & KEY_LEFT)  { if (player_x > 16)  player_x -= 2; }
        if (pad & KEY_RIGHT) { if (player_x < 220) player_x += 2; }
        if (pad & KEY_UP)    { if (player_y > 32)  player_y -= 2; }
        if (pad & KEY_DOWN)  { if (player_y < 200) player_y += 2; }

        // Sincroniza com o vídeo
        WaitForVBlank();
    }

    return 0;
}
