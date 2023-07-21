package group4618.pozdnyakov.lesson1.exercise1;

import java.util.List;

public interface VendingMachine {
    void initProducts(List<Product> products);

    Product getProduct(String name);
}
