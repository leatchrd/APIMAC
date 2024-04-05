<template>
  <div class="character-card">
    <img :src="character.image" class="character-image" alt="Character Image">
    <p class="character-name">{{ character.name }}</p>
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
  background-color: #ffffff;
  border-radius: 10px;
  padding: 10px;
  text-align: center;
}

.character-image {
  width: 100%;
  border-radius: 10px;
}

.character-name {
  margin-top: 10px;
}
</style>
