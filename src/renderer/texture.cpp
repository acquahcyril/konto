#include "renderer/texture.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <stb_image.h>

namespace kt {

Texture::~Texture() { glDeleteTextures(1, &textureId); }

void Texture::CreateTexture(const std::filesystem::path &imagePath) {
  int width, height, channels;
  stbi_set_flip_vertically_on_load(1);
  stbi_uc *data = stbi_load(imagePath.c_str(), &width, &height, &channels, 0);
  CreateTexture(data, width, height, channels);
  stbi_image_free(data);
}

void Texture::CreateTexture(const void *data, int width, int height,
                            int channels) {
  if (data) {
    GLenum internalFormat = 0, dataFormat = 0;
    if (channels == 4) {
      internalFormat = GL_RGBA8;
      dataFormat = GL_RGBA;
    } else if (channels == 3) {
      internalFormat = GL_RGB8;
      dataFormat = GL_RGB;
    }
    glCreateTextures(GL_TEXTURE_2D, 1, &textureId);
    glTextureStorage2D(textureId, 1, internalFormat, width, height);

    glTextureParameteri(textureId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(textureId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureParameteri(textureId, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(textureId, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTextureSubImage2D(textureId, 0, 0, 0, width, height, dataFormat,
                        GL_UNSIGNED_BYTE, data);
  }
}

uint32_t Texture::GetId() const { return textureId; }

void Texture::Bind(uint32_t slot) const { glBindTextureUnit(slot, textureId); }

} // namespace kt
