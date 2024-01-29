<template>
  Hello World
  <test />
  <!-- étape 3 de l'import : placer le nom du fichier dans le html -->
</template>

<script>
import test from "./test.vue"; // étape 1 de l'import : indiquer le chemin qu'à l'autre fichier, sinon on peut utiliser @ et on revient au fichier src ou alors pour remonter d'un fichier ../


// bidule()
export default { // étape 2 de l'import : indiquer le nom de l'objet pour pouvoir le mettre dans le html
  components: {
    test,
  },
};
</script>

// extension: vetur