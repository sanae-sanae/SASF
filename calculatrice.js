const readline = require('readline');

// Interface readline pour lire les entrées de l'utilisateur
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Classe pour effectuer les calculs
class Calculator {
  add(a, b) {
    return a + b;
  }

  subtract(a, b) {
    return a - b;
  }

  multiply(a, b) {
    return a * b;
  }

  divide(a, b) {
    if (b === 0) {
      throw new Error("Erreur : Division par zéro !");
    }
    return a / b;
  }

  power(a, b) {
    return Math.pow(a, b);
  }

  sqrt(a) {
    if (a < 0) {
      throw new Error("Erreur : ax katdir almkalakh rah  La racine carrée d'un nombre négatif n'est pas définie !");
    }
    return Math.sqrt(a);
  }

  factorial(n) {
    if (n < 0) {
      throw new Error("Erreur : La factorielle n'est définie que pour les entiers positifs !");
    }
    let result = 1;
    for (let i = 1; i <= n; i++) {
      result *= i;
    }
    return result;
  }
}

// Classe pour valider les entrées utilisateur
class InputValidator {
  static isValidNumber(input) {
    const num = parseFloat(input);
    return !isNaN(num);
  }

  static getValidatedNumber(prompt) {
    return new Promise((resolve, reject) => {
      rl.question(prompt, (input) => {
        if (InputValidator.isValidNumber(input)) {
          resolve(parseFloat(input));
        } else {
          reject("Erreur : Veuillez entrer un nombre valide !");
        }
      });
    });
  }

  static getValidatedOperation() {
    return new Promise((resolve) => {
      rl.question('Choisissez une opération (+, -, *, /, ^, √, !) : ', (operation) => {
        const validOperations = ['+', '-', '*', '/', '^', '√', '!'];
        if (validOperations.includes(operation)) {
          resolve(operation);
        } else {
          resolve(null);
        }
      });
    });
  }
}

// Fonction pour afficher le menu
async function displayMenu() {
  console.log("\n=== Calculatrice ===");
  console.log("1. Addition (+)");
  console.log("2. Soustraction (-)");
  console.log("3. Multiplication (*)");
  console.log("4. Division (/)");
  console.log("5. Puissance (^)");
  console.log("6. Racine carrée (√)");
  console.log("7. Factorielle (!)");
  console.log("8. Quitter");

  const choice = await new Promise((resolve) => {
    rl.question('Choisissez une option : ', resolve);
  });

  return choice;
}

// Fonction principale pour gérer le calcul
async function startCalculator() {
  const calculator = new Calculator();

  while (true) {
    const choice = await displayMenu();
    
    if (choice === '8') {
      console.log("Au revoir !");
      rl.close();
      break;
    }

    try {
      let num1, num2, result;
      let operation = null;

      if (choice === '6' || choice === '7') {
        // Racine carrée ou factorielle n'ont qu'un seul argument
        num1 = await InputValidator.getValidatedNumber('Entrez un nombre : ');

        if (choice === '6') {
          result = calculator.sqrt(num1);
        } else if (choice === '7') {
          result = calculator.factorial(num1);
        }
      } else {
        // Pour les autres opérations, nous avons besoin de deux nombres
        num1 = await InputValidator.getValidatedNumber('Entrez le premier nombre : ');
        num2 = await InputValidator.getValidatedNumber('Entrez le second nombre : ');
        operation = await InputValidator.getValidatedOperation();

        if (!operation) {
          console.log("Opération invalide");
          continue;
        }

        // Effectuer l'opération choisie
        switch (operation) {
          case '+':
            result = calculator.add(num1, num2);
            break;
          case '-':
            result = calculator.subtract(num1, num2);
            break;
          case '*':
            result = calculator.multiply(num1, num2);
            break;
          case '/':
            result = calculator.divide(num1, num2);
            break;
          case '^':
            result = calculator.power(num1, num2);
            break;
        }
      }

      console.log(`Le résultat est : ${result}`);

    } catch (error) {
      console.log(error.message);
    }
  }
}

// Démarrer la calculatrice
startCalculator();
