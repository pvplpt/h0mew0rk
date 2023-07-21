package group4618.pozdnyakov.lesson1.exercise1;

import java.util.List;

public class HotBeverageVendingMachine implements VendingMachine {
    private List<Product> products;

    public HotBeverageVendingMachine(List<Product> products) {
        initProducts(products);
    }

    @Override
    public Product getProduct(String name) {
        for (Product product : products) {
            if (product.getName().equalsIgnoreCase(name)) {
                products.remove(product);
                return product;
            }
        }
        return null;
    }

    public HotBeverage getProduct(String name, int temperature) {
        for (Product product : products) {
            if (product instanceof HotBeverage) {
                if (product.getName().equalsIgnoreCase(name) && ((HotBeverage) product).getTemperature() == temperature) {
                    products.remove(product);
                    return (HotBeverage) product;
                }
            }
        }
        return null;
    }

    public HotBeverage getProduct(String name, int volume, int temperature) {
        for (Product product : products) {
            if (product instanceof HotBeverage) {
                if (product.getName().equalsIgnoreCase(name) && ((HotBeverage) product).getVolume() == volume
                        && ((HotBeverage) product).getTemperature() == temperature) {
                    products.remove(product);
                    return (HotBeverage) product;
                }
            }
        }
        return null;
    }

    @Override
    public void initProducts(List<Product> products) {
        this.products = products;
    }

}
