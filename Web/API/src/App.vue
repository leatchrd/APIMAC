<template>
  <div class="dogs-gallery">
    <DogCard :firstname="'Pluto'" :breed="'Saint-Hubert'" :pictureUrl="'https://my-best-kennel.com/pictures/45.png'"/>
    <DogCard :firstname="'Rex'" :breed="'Labrador'" :pictureUrl="'https://my-best-kennel.com/pictures/46.png'"/>
  </div>
</template>

<script>
import getDogsData from "./components/dogsRepository.js";

export default {
  name: 'DogsGallery',
  props: {
    firstname: { type: String, required: true },
    breed: { type: String, required: true },
    pictureUrl: { type: String, default: "https://my-best-kennel.com/pictures/default.png" }
  },

  data(){
    return{
        dogsData: []
    }
  },

  methods: {
    async retrieveDogsData(){
        const myData = await getDogsData()
    }
  }
}
</script>

<style>
.dogs-gallery {
  display: flex;
}
</style>
