#include <iostream>
#include <string>

using namespace std;

struct Recipe {
	string name;
	string ingredients[7];
	int cookingTime;
	int price;
	bool isVanyaDish;
};

void PrintRecipe(const Recipe& recipe) {
	cout << "Recipe: " << recipe.name << endl;
	for (int i = 0; i < 7; i++) {
		cout << "- " << recipe.ingredients[i] << endl;
	}
	cout << "Cooking time: " << recipe.cookingTime << " minutes" << endl;
	cout << "Price: " << recipe.price << " UAN" << endl;
	cout << "This is Vanua Dish: ";
	if (recipe.isVanyaDish)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}
void ChangeRecipe(Recipe& recipe) {
	recipe.price = 280;
	recipe.cookingTime = 50;
	recipe.ingredients[0] = "Spagetti";
	recipe.ingredients[1] = "Mince";
	recipe.ingredients[2] = "Tomato Souce";
	recipe.ingredients[3] = "Onion";
	recipe.ingredients[4] = "Garlic";
	recipe.ingredients[5] = "Parmesan Cheese";
	recipe.ingredients[6] = "Olive Oil";
}

int main() {

	Recipe recipe = {
		"Spagetti",{"Mince","Tomato Souce","Onion","Garlic","Parmesan Cheese","Olive Oil"},
		45, 250, true };
	PrintRecipe(recipe);
	cout << " " << endl<< "After change : " << " " << endl << endl;
	ChangeRecipe(recipe);
	PrintRecipe(recipe);
	return 0;
}