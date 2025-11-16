#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <cstdint>
#include <filesystem>

namespace kt {

class Texture {
public:
  ~Texture();
  void CreateTexture(const std::filesystem::path &imagePath);
  void CreateTexture(const void *data, int width, int height, int channels);

  uint32_t GetId() const;
  void Bind(uint32_t slot) const;

private:
  uint32_t textureId{};
};

} // namespace kt

#endif // !__TEXTURE_H__
