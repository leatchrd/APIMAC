<template>
  <div class="character-card">
    <img :src="character.imageUrl" alt="Character Image" class="character-image" />
    <p>{{ character.name }}</p>
  </div>
</template>

<script>
export default {
  props: {
    character: {
      type: Object,
      required: true
    }
  }
};
</script>

<style>
.character-card {
  background-color: white;
  border-radius: 10px;
  padding: 10px;
  text-align: center;
}

.character-image {
  border-radius: 10px;
  width: 100%;
  height: auto;
  margin-bottom: 10px;
}
</style>
