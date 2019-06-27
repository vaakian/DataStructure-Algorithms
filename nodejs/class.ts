class Product {
    private name: String;
    private price: Number;

    constructor(name: String, price: Number) {
        this.name = name;
        this.price = price;
    }
    
    SetName(name: String) {
        this.name = name;
    }

    Display() {
        console.log(`PRODUCT{ NAME: ${this.name}, Price: ${this.price} }`);
    }

}

const product = new Product('Potato', 36.45);
product.Display();
console.log(product.name);