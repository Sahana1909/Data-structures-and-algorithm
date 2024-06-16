// Function to calculate and display the area of each shape
void displayAreas(union Shape shapes[], int numShapes) {
    printf("Areas of shapes:\n");
    for (int i = 0; i < numShapes; i++) {
        double area;
        switch (shapes[i].circle.radius) {
            case CIRCLE:
                area = calculateCircleArea(shapes[i].circle);
                printf("Area of circle %d: %.2f\n", i + 1, area);
                break;
            case SQUARE:
                area = calculateSquareArea(shapes[i].square);
                printf("Area of square %d: %.2f\n", i + 1, area);
                break;
            case RECTANGLE:
                area = calculateRectangleArea(shapes[i].rectangle);
                printf("Area of rectangle %d: %.2f\n", i + 1, area);
                break;
        }
    }
}

// Function to find the largest area among the shapes
double findLargestArea(union Shape shapes[], int numShapes) {
    double largestArea = 0.0;
    for (int i = 0; i < numShapes; i++) {
        double area;
        switch (shapes[i].circle.radius) {
            case CIRCLE:
                area = calculateCircleArea(shapes[i].circle);
                break;
            case SQUARE:
                area = calculateSquareArea(shapes[i].square);
                break;
            case RECTANGLE:
                area = calculateRectangleArea(shapes[i].rectangle);
                break;
        }
        if (area > largestArea) {
            largestArea = area;
        }
    }
    return largestArea;
}
int main() {
    int numShapes;

    // the user to enter the number of shapes
    printf("Enter the number of shapes: ");
    scanf("%d", &numShapes);

    // Dynamically allocate memory to store the shapes
    union Shape* shapes = (union Shape*)malloc(numShapes * sizeof(union Shape));
    if (shapes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read details for each shape
    for (int i = 0; i < numShapes; i++) {
        int shapeType;
        printf("Enter type of shape (0 for circle, 1 for square, 2 for rectangle) for shape %d: ", i + 1);
        scanf("%d", &shapeType);
        switch (shapeType) {
            case CIRCLE:
                printf("Enter radius of circle: ");
                scanf("%lf", &shapes[i].circle.radius);
                break;
            case SQUARE:
                printf("Enter side length of square: ");
                scanf("%lf", &shapes[i].square.sideLength);
                break;
            case RECTANGLE:
                printf("Enter length and width of rectangle: ");
                scanf("%lf %lf", &shapes[i].rectangle.length, &shapes[i].rectangle.width);
                break;
            default:
                printf("Invalid shape type\n");
                free(shapes);
                return 1;
        }
    }
    // Display the area of each shape
    displayAreas(shapes, numShapes);

    // Find and print the largest area among the shapes
    double largestArea = findLargestArea(shapes, numShapes);
    printf("\nLargest area among the shapes: %.2f\n", largestArea);

    // Free dynamically allocated memory
    free(shapes);

    return 0;
}

