// Add to menu options:
void print_menu() {
    printf("\n🎮 SIMULATION MENU:\n");
    printf("1. 🚨 Trigger Panic Button\n");
    printf("2. 🎤 Simulate Voice Trigger\n");
    printf("3. 🎯 Change GPS Location\n");
    printf("4. 🔧 Voice Settings\n");
    printf("5. 📊 Show System Status\n");
    printf("0. ❌ Exit Simulator\n");
    printf("Choose an option: ");
}

// Add voice settings submenu:
void voice_settings_menu() {
    int choice;
    char phrase[64];
    int sensitivity;
    
    do {
        printf("\n🎤 VOICE SETTINGS:\n");
        printf("1. Change Trigger Phrase\n");
        printf("2. Adjust Sensitivity\n");
        printf("3. Toggle Voice Activation\n");
        printf("4. Test Voice Recognition\n");
        printf("0. Back to Main Menu\n");
        printf("Choose: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Current phrase: '%s'\n", "help emergency");
                printf("New trigger phrase: ");
                scanf("%63s", phrase);
                guardian_set_trigger_phrase(phrase);
                break;
                
            case 2:
                printf("Current sensitivity: 70%%\n");
                printf("New sensitivity (0-100): ");
                scanf("%d", &sensitivity);
                voice_engine_set_sensitivity(sensitivity);
                break;
                
            case 3:
                printf("Voice activation is currently ON\n");
                printf("Toggle? (1=ON, 0=OFF): ");
                scanf("%d", &choice);
                guardian_set_voice_activation(choice);
                break;
                
            case 4:
                printf("🎤 Testing voice recognition...\n");
                for (int i = 0; i < 5; i++) {
                    voice_engine_process();
                    usleep(300000);
                }
                break;
        }
    } while (choice != 0);
}