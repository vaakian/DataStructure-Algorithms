var Product = /** @class */ (function () {
    function Product(name, price) {
        this.name = name;
        this.price = price;
    }
    Product.prototype.SetName = function (name) {
        this.name = name;
    };
    Product.prototype.Display = function () {
        console.log("PRODUCT{ NAME: " + this.name + ", Price: " + this.price + " }");
    };
    return Product;
}());
var product = new Product('Potato', 36.45);
product.Display();
console.log(product.name);
