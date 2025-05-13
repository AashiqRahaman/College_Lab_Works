import face_recognition
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from hashlib import sha256
import os

# Load an image file (face of a doctor)
image_path = "doctor.jpg"  # 🔁 Replace with path to your test image (JPG/PNG)
image = face_recognition.load_image_file(image_path)
encodings = face_recognition.face_encodings(image)

if not encodings:
    print("❌ No face found in the image. Try another image with a clear front face.")
else:
    # Step 1: Generate 128D encoding
    face_encoding = encodings[0]

    # Step 2: Hash the encoding into a 256-bit AES key
    key = sha256(face_encoding.tobytes()).digest()

    # Step 3: Encrypt dummy medical image content
    message = b"This is sensitive medical image data."
    iv = os.urandom(16)  # Random IV for AES
    cipher = Cipher(algorithms.AES(key), modes.CFB(iv))
    encryptor = cipher.encryptor()
    ciphertext = encryptor.update(message) + encryptor.finalize()

    # Step 4: Decrypt the ciphertext
    decryptor = cipher.decryptor()
    decrypted = decryptor.update(ciphertext) + decryptor.finalize()

    print("\n🔐 Encryption Successful:")
    print("Original Message:", message)
    print("Encrypted (hex):", ciphertext.hex())
    print("Decrypted Message:", decrypted)
    print("AES Key (hex):", key.hex())
    print("IV (hex):", iv.hex())
