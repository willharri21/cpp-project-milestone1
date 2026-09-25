#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include "Game.h"
#include "Character.h"
#include "Move.h"
#include "CheeseStrategy.h"
#include "Glossary.h"
#include "GlossaryTerm.h"
#include "Slang.h"
#include "SlangTerm.h"

int getValidatedInt(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        if (!std::cin) {
            // Input stream ended (EOF/redirected input ran out) rather than
            // the user typing something invalid. Exit cleanly instead of
            // looping forever on empty reads.
            std::cout << "\nInput ended unexpectedly. Exiting.\n";
            std::exit(0);
        }

        try {
            size_t pos = 0;
            int value = std::stoi(line, &pos);
            if (pos != line.size()) {
                std::cout << "That's not a valid whole number. Try again.\n";
                continue;
            }
            return value;
        } catch (const std::invalid_argument&) {
            std::cout << "That's not a valid whole number. Try again.\n";
        } catch (const std::out_of_range&) {
            std::cout << "That number's too large. Try again.\n";
        }
    }
}

// Adds a character to the roster with no moves logged yet. Used for roster
// entries added to complete the cast, where verified frame data hasn't
// been sourced yet. Better to be accurate about what's missing than to
// invent numbers.
void addRosterOnly(Game& game, const std::string& name, const std::string& archetype) {
    game.addCharacter(Character(name, archetype));
}

Game buildRivalsOfAether2() {
    Game roa2("Rivals of Aether 2", "Aether Studios");

    // --- Characters with verified move/frame data ---
    Character ranno("Ranno", "Fast rushdown / poison zoner");
    ranno.addMove({ "Jab 1", "Attack", 6, 8, 6,
        "Very fast, low commitment. Cancels into Tilts or a Rapid Jab finisher. "
        "Weak to floorhugging, so it's best used on airborne or shielding opponents." });
    ranno.addMove({ "Back Air", "Aerial Attack (facing away)", 5, 20, 16,
        "Reliable spacing and kill tool with a wide active window. "
        "Interruptible around frame 37, so respect the recovery if it's blocked." });
    roa2.addCharacter(ranno);

    Character clairen("Clairen", "Disjointed swordsman");
    clairen.addMove({ "Forward Tilt", "Tilt Attack", 12, 15, 8,
        "Strong horizontal disjoint used to control space. "
        "Slower than Jab but keeps opponents out further; good anti-approach tool." });
    clairen.addMove({ "Neutral Special", "Special Attack", 10, 14, 12,
        "Plasma trail projectile-style move. Useful for zoning and setting up follow-ups "
        "at mid-range rather than as a raw punish tool." });
    roa2.addCharacter(clairen);

    Character zetterburn("Zetterburn", "Fast, combo-heavy \"spacie\"");
    zetterburn.addMove({ "Shine", "Down Special", 2, 4, 10,
        "Frame 2 startup covering his body, cancellable into a jump. The core of his "
        "shield pressure, combo game, and one of the fastest, most versatile options in the cast." });
    zetterburn.addMove({ "Up Strong", "Strong Attack (up)", 8, 11, 14,
        "Fast anti-air with strong kill power, similar to a traditional fighting-game uppercut. "
        "One of his most consistent finishers out of Shine combos." });
    roa2.addCharacter(zetterburn);

    // --- Remaining roster: names/archetypes confirmed, move data TBD ---
    addRosterOnly(roa2, "Fleet", "Newcomer from the Dungeons of Aether spin-off");
    addRosterOnly(roa2, "Forsburn", "Fire Rival who hides in smoke, creates decoys, and builds toward an explosive finisher");
    addRosterOnly(roa2, "Kragg", "Earth Rival who creates rock walls and pillars for stage control and recovery");
    addRosterOnly(roa2, "Loxodont", "Elephant-themed newcomer, originally a non-playable character in the first game");
    addRosterOnly(roa2, "Maypul", "Earth Rival who marks opponents and uses plant traps with vine-based movement");
    addRosterOnly(roa2, "Orcane", "Water Rival who creates puddles to teleport through and uses bubbles for space control");
    addRosterOnly(roa2, "Wrastor", "Air Rival with four jumps and wind-current-based aerial pressure");
    addRosterOnly(roa2, "Etalus", "Ice-themed DLC fighter (added January 2025)");
    addRosterOnly(roa2, "Olympia", "Earth Rival from the Crystal Oasis using gemstone-powered martial arts");
    addRosterOnly(roa2, "Absa", "DLC fighter (added July 2025)");
    addRosterOnly(roa2, "Galvan", "Original newcomer (added October 2025), previously referenced in Dreams of Aether");
    addRosterOnly(roa2, "La Reina", "Anthropomorphic wrestling insect, winner of the Workshop Character Creation Contest");
    addRosterOnly(roa2, "Slade", "Dungeons of Aether protagonist (added April 2026)");
    addRosterOnly(roa2, "Gouie", "DLC fighter (added August 2026)");

    roa2.addCheeseStrategy({ "Ranno poison stacking loop",
        "Repeatedly applying poison through disjointed pokes rather than committing to risky "
        "combos. Whittles down percent safely and punishes opponents who don't respect zoning "
        "by trying to force their way in." });
    roa2.addCheeseStrategy({ "Zetterburn Shine ledge trap",
        "Using Shine's frame-2 startup near the ledge to blanket-cover an opponent's likely getup "
        "options. Effective against players with predictable ledge habits, though it loses to "
        "getup attacks with enough disjoint or invincibility." });

    return roa2;
}

Game buildGuiltyGearStrive() {
    Game ggst("Guilty Gear Strive", "Arc System Works");

    // --- Character with verified move/frame data ---
    Character sol("Sol Badguy", "Aggressive rushdown brawler");
    sol.addMove({ "5K", "Kick (standing)", 5, 6, 10,
        "Fast 5-frame knee that hits twice and doesn't whiff on crouching opponents the "
        "way 5P can. Both hits are jump/dash cancelable, making it a strong combo starter." });
    sol.addMove({ "Sidewinder Ignited", "214H (Special)", 12, 14, 10,
        "Rising uppercut-style special, roughly -10 on block/hit at minimum height. "
        "Used to convert combos rather than as a safe pressure tool given the frame disadvantage." });
    ggst.addCharacter(sol);

    // --- Remaining roster: names/archetypes confirmed, move data TBD ---
    addRosterOnly(ggst, "Ky Kiske", "All-rounder swordsman with strong pressure and disjointed normals");
    addRosterOnly(ggst, "May", "Anchor-and-dolphin zoner/rushdown hybrid with unconventional range");
    addRosterOnly(ggst, "Potemkin", "Heavy grappler with command grabs and armored normals");
    addRosterOnly(ggst, "Chipp Zanuff", "High-speed ninja rushdown with wall-cling mobility");
    addRosterOnly(ggst, "Faust", "Unpredictable zoner built around randomized item throws");
    addRosterOnly(ggst, "Millia Rage", "Mobile rushdown using hair-based disjointed attacks");
    addRosterOnly(ggst, "Giovanna", "Fast, technical rushdown martial artist with strong mobility tools");
    addRosterOnly(ggst, "I-No", "Unorthodox zoner/rushdown hybrid using guitar-based specials");

    ggst.addCheeseStrategy({ "Sol 5K anti-mash loop",
        "Using 5K's fast startup to counter-poke opponents who mash buttons after your blockstrings "
        "end, rather than respecting your frame advantage. Simple but effective against players "
        "who haven't learned your pressure's true gaps yet." });
    ggst.addCheeseStrategy({ "Faust item-throw stall",
        "Repeatedly using Faust's item-throw special defensively to control neutral against "
        "opponents unfamiliar with the randomness. Buys time and space in tough matchups, "
        "though it's less effective against players who already know the item pool." });

    return ggst;
}

Glossary buildGlossary() {
    Glossary glossary;

    glossary.addTerm({ "Wavedash",
        "A tech using a jump immediately cancelled into an airdodge into the ground, "
        "giving fast horizontal movement with very little landing lag.",
        "Used to close distance quickly while staying in a low-commitment, actionable state." });
    glossary.addTerm({ "Whiff Punish",
        "Attacking an opponent right after one of their moves misses, "
        "capitalizing on the recovery frames (endlag) they're stuck in.",
        "If an opponent throws a slow attack that misses, punishing it before they can act again." });
    glossary.addTerm({ "Floorhugging",
        "A defensive option where a grounded character takes reduced knockback "
        "from certain low-power hits, staying on the ground instead of being launched.",
        "Ranno's Jab can be floorhugged by grounded opponents, reducing its follow-up potential." });
    glossary.addTerm({ "IASA",
        "Short for 'Interruptible As Soon As' \u2014 the exact frame a character "
        "can act again after using a move, even if the move's animation is still playing.",
        "A move with IASA frame 37 means the character can act on frame 37 even if recovery visually continues." });
    glossary.addTerm({ "Tiltboost",
        "Cancelling the startup of a Jab with a directional input to slide into a Tilt attack, "
        "gaining extra forward distance compared to using the Tilt on its own.",
        "Jab-cancelling into Forward Tilt to close extra distance before the Tilt's hitbox comes out." });
    glossary.addTerm({ "DACUS",
        "Short for 'Dash Attack Cancelled Up Strong' \u2014 cancelling the first few frames of a "
        "Dash Attack into a grounded Up Strong, letting a fast-moving dash lead into a kill move.",
        "Dashing in and DACUS-ing into Up Strong to convert horizontal momentum into a kill confirm." });
    glossary.addTerm({ "Meaty",
        "An attack timed so its hitbox becomes active as early as possible on an opponent's "
        "wakeup or landing, minimizing the window they have to react or interrupt.",
        "Timing a meaty attack right as an opponent gets up from a knockdown to stay safely ahead." });
    glossary.addTerm({ "Okizeme",
        "The offense applied to a knocked-down or landing opponent, covering their wakeup "
        "options with attacks, mixups, or positioning before they can act freely again.",
        "Setting up strong okizeme after a knockdown to keep pressure going instead of resetting neutral." });
    glossary.addTerm({ "Frame Trap",
        "A gap left between two attacks that's too short for the opponent to act in safely, but "
        "long enough to punish them if they try to press a button during it.",
        "Leaving a 3-frame gap in a blockstring that punishes a 4-frame jab attempt with a bigger hit." });
    glossary.addTerm({ "Blockstring",
        "A sequence of attacks performed while an opponent blocks, chained closely enough "
        "together that they can't act freely between hits.",
        "Running a blockstring to keep an opponent locked down before going for a frame trap or throw." });

    return glossary;
}

Slang buildSlang() {
    Slang slang;

    slang.addTerm({ "GG",
        "Short for 'Good Game.' Said at the end of a match regardless of outcome, as a basic sign "
        "of sportsmanship and respect toward your opponent.",
        "Typing 'GG' in chat after a close set, win or lose." });
    slang.addTerm({ "Salty",
        "Frustrated or visibly upset after a loss, especially one that felt close or avoidable.",
        "Getting salty after dropping a combo that would have won the set." });
    slang.addTerm({ "Bodied",
        "Being decisively and thoroughly defeated in a match, with little room for argument about the outcome.",
        "Getting bodied 3-0 without taking a single game." });
    slang.addTerm({ "Scrub",
        "A player who blames losses on external factors (lag, luck, 'cheap' tactics) rather than "
        "acknowledging skill gaps or bad habits in their own play, a term popularized by David Sirlin's essay 'Playing to Win.'",
        "Calling a legal, in-game tactic 'cheap' instead of learning to deal with it is a classic scrub mindset." });
    slang.addTerm({ "Footsies",
        "The neutral-game battle of positioning and spacing that happens before either player "
        "commits to a real attack, built on baiting whiffs and controlling distance.",
        "Winning the footsies battle by staying just outside an opponent's range until they whiff." });
    slang.addTerm({ "Yomi",
        "Reading and predicting an opponent's next action based on habits, tendencies, or the "
        "current situation, rather than reacting after the fact.",
        "Having good yomi on an opponent's wakeup habits to call out their favorite escape option." });
    slang.addTerm({ "Rage Quit",
        "Disconnecting from or abandoning a match out of frustration before it officially ends.",
        "Rage quitting after getting caught by the same combo three times in a row." });
    slang.addTerm({ "Ganked",
        "Being caught off guard by an unexpected, unconventional, or unusually strong attack or setup.",
        "Getting ganked by an off-stage read nobody saw coming." });

    return slang;
}

void runCharacterMenu(Game& game) {
    int choice = -1;
    while (choice != 0) {
        game.listCharacters();
        std::cout << "0. Back\n";
        choice = getValidatedInt("Choose a character to view their moves: ");
        if (choice == 0) break;
        Character* selected = game.getCharacter(choice - 1);
        if (selected == nullptr) {
            std::cout << "No character at that number. Try again.\n";
        } else {
            selected->listMoves();
        }
    }
}

void runCheeseMenu(Game& game) {
    int choice = -1;
    while (choice != 0) {
        game.listCheeseStrategies();
        std::cout << "0. Back\n";
        choice = getValidatedInt("Choose a strategy to view: ");
        if (choice == 0) break;
        game.showCheeseStrategy(choice - 1);
    }
}

void runSingleGameMenu(Game& game) {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== " << game.getTitle() << " ===\n";
        std::cout << "1. Browse Characters\n";
        std::cout << "2. View Cheese Strategies\n";
        std::cout << "0. Back to game list\n";
        choice = getValidatedInt("Choose an option: ");
        if (choice == 1) {
            runCharacterMenu(game);
        } else if (choice == 2) {
            runCheeseMenu(game);
        } else if (choice != 0) {
            std::cout << "Invalid option, try again.\n";
        }
    }
}

void runGameMenu(std::vector<Game>& games) {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n--- Games ---\n";
        for (size_t i = 0; i < games.size(); ++i) {
            std::cout << (i + 1) << ". " << games[i].getTitle() << "\n";
        }
        std::cout << "0. Back to main menu\n";
        choice = getValidatedInt("Choose a game to browse: ");
        if (choice == 0) break;
        if (choice < 1 || choice > static_cast<int>(games.size())) {
            std::cout << "No game at that number. Try again.\n";
        } else {
            runSingleGameMenu(games[choice - 1]);
        }
    }
}

void runGlossaryMenu(Glossary& glossary) {
    int choice = -1;
    while (choice != 0) {
        glossary.listTerms();
        std::cout << "0. Back to main menu\n";
        choice = getValidatedInt("Choose a term to view its definition: ");
        if (choice == 0) break;
        glossary.showDefinition(choice - 1);
    }
}

void runSlangMenu(Slang& slang) {
    int choice = -1;
    while (choice != 0) {
        slang.listTerms();
        std::cout << "0. Back to main menu\n";
        choice = getValidatedInt("Choose a term to view its meaning: ");
        if (choice == 0) break;
        slang.showMeaning(choice - 1);
    }
}

int main() {
    std::vector<Game> games;
    games.push_back(buildRivalsOfAether2());
    games.push_back(buildGuiltyGearStrive());

    Glossary glossary = buildGlossary();
    Slang slang = buildSlang();
    int choice = -1;

    std::cout << "=== Project BallKnowledge ===\n";
    std::cout << "Fighting Game Tips, Tricks & Frame Data Reference\n";

    while (choice != 0) {
        std::cout << "\n1. Browse Games (" << games.size() << " loaded)\n";
        std::cout << "2. View Glossary\n";
        std::cout << "3. View FGC Slang\n";
        std::cout << "0. Exit\n";

        choice = getValidatedInt("Choose an option: ");

        if (choice == 1) {
            runGameMenu(games);
        } else if (choice == 2) {
            runGlossaryMenu(glossary);
        } else if (choice == 3) {
            runSlangMenu(slang);
        } else if (choice != 0) {
            std::cout << "Invalid option, try again.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
