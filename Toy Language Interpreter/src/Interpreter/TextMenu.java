package Interpreter;

import Interpreter.Commands.*;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class TextMenu {
    private Map<String, Command> commands;

    public TextMenu() {
        commands = new HashMap<>();
    }

    public void addCommand(Command c) {
        commands.put(c.getKey(), c);
    }

    private void printMenu() {
        for (Command com : commands.values()) {
            String line = String.format("%4s : %s", com.getKey(), com.getDesciprtion());

        }
    }

    public void show() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            printMenu();
            System.out.print("Input choice: ");
            String key = scanner.nextLine();
//            Command com = commands.get(key);
//            if(com == null) {
//                System.out.print("Invalid Option\n");
//                continue;
//            }
//            com.execute();
//            }
        }
    }
}
