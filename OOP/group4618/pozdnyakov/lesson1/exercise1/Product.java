package group4618.pozdnyakov.lesson1.exercise1;

public abstract class Product {
    private String name;
    private double cost;
    

    public Product(String name, double cost) {
        this.name = name;
        this.cost = cost;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    @Override
    public String toString() {
        return String.format("Product{name='%s',cost=%f}", name, cost);
    }
}
