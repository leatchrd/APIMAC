
<template>
    <div class="background">
      <!-- Contenu de l'arrière-plan -->
    </div>
  </template>
  
<script>
  export default {
    // Ajoutez vos données, méthodes, etc.
  };
</script>
  
<style scoped>
.background {
  background-image: url('@/assets/APIBackground.jpg');
  background-size: cover;
  background-position: center;
  background-repeat: no-repeat;
  background-attachment: fixed;
  height: 100vh;
  display: flex;
  align-items: center;
  justify-content: center;
  z-index: -1;
}

@media screen and (max-width: 600px) {
  /* Pour les écrans de téléphone */
  .background {
    background-size: contain;
  }
}
</style>
