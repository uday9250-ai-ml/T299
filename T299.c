#include <stdio.h>
#include <string.h>


struct Player {
    char name[50];
    int score;
    int waterLevel;
};


void playScenario(struct Player *p, const char scenario[]) {
    printf("\nScenario: %s\n", scenario);
    printf("Choose an action:\n");
    printf("1. Use Micro-Irrigation\n");
    printf("2. Artificial Recharge\n");
    printf("3. Do Nothing\n");

    int choice;
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("✅ Good choice! Efficient irrigation used.\n");
            p->score += 10;
            p->waterLevel += 5;
            break;
        case 2:
            printf("🌧 Great! Groundwater recharged successfully.\n");
            p->score += 15;
            p->waterLevel += 10;
            break;
        case 3:
            printf("⚠ Oops! No action led to water issues.\n");
            p->score -= 5;
            p->waterLevel -= 10;
            break;
        default:
            printf("❌ Invalid choice. No action taken.\n");
    }

    
    if (p->waterLevel > 100) p->waterLevel = 100;
    if (p->waterLevel < 0) p->waterLevel = 0;

    printf("Current Score: %d | Water Level: %d%%\n", p->score, p->waterLevel);
}

int main() {
    struct Player player;

    printf("🌊 Welcome to the Groundwater Conservation Game 🌊\n");
    printf("Enter your name: ");
    scanf("%s", player.name);

    player.score = 0;
    player.waterLevel = 50; 

    
    playScenario(&player, "1. Drought Alert!");
    playScenario(&player, "2. Heavy Rainfall Season");
    playScenario(&player, "3. Water Table Contamination");

    
    printf("\n🎮 --- Game Summary --- 🎮\n");
    printf("Player Name: %s\n", player.name);
    printf("Final Score: %d\n", player.score);
    printf("Final Groundwater Level: %d%%\n", player.waterLevel);

    
    if (player.score >= 30) {
        printf("🏆 Congratulations! You're a Water-Smart Hero!\n");
    } else {
        printf("💡 Try again and learn to conserve better!\n");
    }

    return 0;
}