package ru.pozdnyakov.lesson5.exercise1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class TelephoneDirectory {
    HashMap<String, List<String>> td = new HashMap<>();

    public TelephoneDirectory() {
    }

    public TelephoneDirectory(String[] phones, String separator) {
        for (String record : phones) {
            String[] recordParts = record.split(separator);
            String surName = recordParts[0];
            String phone = recordParts[1];
            if (td.containsKey(surName)) {
                td.get(surName).add(phone);
            } else {
                ArrayList<String> lst = new ArrayList<>();
                lst.add(phone);
                td.put(surName, lst);
            }
        }
    }

    public void add(String surName, String phone) {
        if (td.containsKey(surName)) {
            td.get(surName).add(phone);
        } else {
            ArrayList<String> lst = new ArrayList<>();
            lst.add(phone);
            td.put(surName, lst);
        }
    }

    public List<String> get(String surName) {
        if (td.containsKey(surName)) {
            return td.get(surName);
        } else {
            return null;
        }
    }

    public String toString() {
        StringBuilder result = new StringBuilder();
        for (String name : td.keySet()) {
            result.append(String.format("%s: %s\n", name, td.get(name).toString()));
        }
        return result.toString();
    }
}
