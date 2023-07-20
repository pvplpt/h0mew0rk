package ru.pozdnyakov.lesson6.exercise1;

import java.util.Objects;

public class Cat {
    private String name; // Кличка
    private String colour; // Окрас
    private String breed; // Порода
    private Double weight; // Вес

    public Cat(String name, String colour, String breed, Double weight) {
        this.name = name;
        this.colour = colour;
        this.breed = breed;
        this.weight = weight;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getColour() {
        return colour;
    }

    public void setColour(String colour) {
        this.colour = colour;
    }

    public String getBreed() {
        return breed;
    }

    public void setBreed(String breed) {
        this.breed = breed;
    }

    public Double getWeight() {
        return weight;
    }

    public void setWeight(Double weight) {
        this.weight = weight;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %.3fкг", breed, colour, name, weight);
    }

    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Cat cat = (Cat) o;
        return cat.name.equals(name) && cat.colour.equals(colour) && cat.breed.equals(breed)
                && cat.weight.equals(weight);

    }

    public int hashCode() {
        return Objects.hash(name, colour, breed, weight);

    }
}
